void __thiscall Scaleform::GFx::CharPosInfo::CharPosInfo(
        Scaleform::GFx::CharPosInfo *this,
        const Scaleform::GFx::CharPosInfo *__that)
{
  Scaleform::GFx::Resource *pObject; // ecx

  qmemcpy((void *)this, __that, 0x40u);
  pObject = (Scaleform::GFx::Resource *)__that->pFilters.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  this->pFilters.pObject = __that->pFilters.pObject;
  this->Ratio = __that->Ratio;
  this->Depth = __that->Depth;
  this->CharacterId.Id = __that->CharacterId.Id;
  this->ClassName = __that->ClassName;
  this->ClipDepth = __that->ClipDepth;
  this->Flags.Flags = __that->Flags.Flags;
  this->BlendMode = __that->BlendMode;
}
