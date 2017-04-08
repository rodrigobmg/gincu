local backgroundImageName = "matchthree/background.png"

local imageName = "testbed/rabbit.png";
local imageSize = port.createSize(120, 103);
local spriteBoardStart = port.createPoint(200, 100);
local spriteBoardSize = port.createSize(500, 400);
local spriteBoardEnd = port.createPoint(spriteBoardStart.x + spriteBoardSize.width, spriteBoardStart.y + spriteBoardSize.height);

SceneTestTween = cpgf.cloneClass(gincu.GSceneWrapper)

local function addEntity(scene, entity)
	scene.addEntity(entity)
end

local function addImage(scene, resourceName, position)
	local result = gincu.GComponentTransform(position)
	addEntity(scene,
		gincu.GEntity()
		.addComponent(result)
		.addComponent(gincu.GComponentAnchor(gincu.GRenderAnchor.center))
		.addComponent(gincu.createAndLoadImageComponent(resourceName))
	);
	return result;
end

local function doTestBasic(me)
	local duration = 2000;

	local sprite = addImage(me, imageName, port.createPoint(spriteBoardStart.x, spriteBoardStart.y));
	local target = addImage(me, imageName, port.createPoint(spriteBoardEnd.x, spriteBoardEnd.y));
	
	--target->getEntity()->getComponentByType<GComponentRender>()->setColor(colorSetAlpha(colorWhite, 127));
	local accessorPosition = gincu.createPointAccessor(sprite, 'getPosition', 'setPosition')
	local accessorRotation = gincu.createFloatAccessor(sprite, 'getRotation', 'setRotation')
	me.getTweenList().tween()
		.duration(2000)
		.targetPoint(accessorPosition, target.getPosition())
		.targetFloat(accessorRotation, 180, 360)
		._repeat(gincu.tweenRepeatInfinitely)
		.yoyo(true)
	;
end

local function onUpdate(me)
--	me.tweenList.tick(gincu.GApplication.getInstance().getFrameMilliseconds());
end

SceneTestTween.doOnEnter = function(me)
	me.addEntity(createBackButton(function(e)
		gincu.GApplication.getInstance().getSceneManager().switchScene(SceneMain())
	end))
	
	me.onUpdateCallback = gincu.createEventCallback(function(e) onUpdate(me) end)
	gincu.GApplication.getInstance().getEventQueue().addListener(gincu.GEventType.update, me.onUpdateCallback)
	
	me.tweenList = gincu.GTweenList()

	local buttonSize = port.createSize(100, 40);
	
	local buttonX = buttonSize.width / 2 + 10;
	local buttonY = 100;
	local yDelta = buttonSize.height + 20;
	
	me.addEntity(createButton(
		"Basic",
		port.createPoint(buttonX, buttonY),
		buttonSize,
		function(e) doTestBasic(me) end
	));
	buttonY = buttonY + yDelta;

end

SceneTestTween.doOnExit = function(me)
	print("SceneTestTween.doOnExit")

	gincu.GApplication.getInstance().getEventQueue().removeListener(gincu.GEventType.update, me.onUpdateCallback)
end
