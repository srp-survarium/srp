void __userpurge Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::CandidateListLoader(
        Scaleform::GFx::AS2::CandidateListLoader *this@<ecx>,
        Scaleform::GFx::AS2::LocalFrame **a2@<ebp>,
        Scaleform::GFx::Resource *pimeManager,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::MovieClipLoader::MovieClipLoader(this, a2, penv);
  this->Scaleform::GFx::AS2::MovieClipLoader::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MovieClipLoader_vtbl *)&Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::MovieClipLoader::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::`anonymous namespace'::CandidateListLoader::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( pimeManager )
    Scaleform::RefCountImpl::AddRef(pimeManager);
  this->pASIMEManager.pObject = (Scaleform::GFx::AS2::IMEManager *)pimeManager;
}
