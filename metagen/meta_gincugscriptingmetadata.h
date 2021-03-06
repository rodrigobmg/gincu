// Auto generated file, don't modify.

#ifndef CPGF_META_GINCUGSCRIPTINGMETADATA_H
#define CPGF_META_GINCUGSCRIPTINGMETADATA_H


#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/gmetapolicy.h"


using namespace gincu;


namespace meta_gincu { 


template <typename D>
void buildMetaClass_Global_gscriptingmetadata(D _d)
{
    (void)_d;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _method("createEventCallback", (EventCallback (*) (cpgf::IScriptFunction *))&createEventCallback);
    _d.CPGF_MD_TEMPLATE _method("createFloatAccessor", (FloatAccessor (*) (const cpgf::GVariant &, const std::string &, const std::string &))&createFloatAccessor, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleCopyConstReference<2> >());
    _d.CPGF_MD_TEMPLATE _method("createPointAccessor", (PointAccessor (*) (const cpgf::GVariant &, const std::string &, const std::string &))&createPointAccessor, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleCopyConstReference<2> >());
    _d.CPGF_MD_TEMPLATE _method("createScaleAccessor", (ScaleAccessor (*) (const cpgf::GVariant &, const std::string &, const std::string &))&createScaleAccessor, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleCopyConstReference<2> >());
    _d.CPGF_MD_TEMPLATE _method("createFloatGetter", (FloatGetter (*) (const cpgf::GVariant &, const std::string &))&createFloatGetter, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("createPointGetter", (PointGetter (*) (const cpgf::GVariant &, const std::string &))&createPointGetter, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("createScaleGetter", (ScaleGetter (*) (const cpgf::GVariant &, const std::string &))&createScaleGetter, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("createSharedPointer", (std::shared_ptr< void > (*) (const cpgf::GVariant &))&createSharedPointer);
}


} // namespace meta_gincu




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif
