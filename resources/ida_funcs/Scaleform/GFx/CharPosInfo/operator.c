Scaleform::GFx::CharPosInfo *__thiscall Scaleform::GFx::CharPosInfo::operator=(
        Scaleform::GFx::CharPosInfo *this,
        const Scaleform::GFx::CharPosInfo *__that)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  qmemcpy((void *)this, __that, 0x34u);
  pObject = (Scaleform::GFx::Resource *)__that->pFilters.pObject;
  this->Matrix_1.M[1][1] = __that->Matrix_1.M[1][1];
  this->Matrix_1.M[1][2] = __that->Matrix_1.M[1][2];
  this->Matrix_1.M[1][3] = __that->Matrix_1.M[1][3];
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pFilters.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->pFilters.pObject = __that->pFilters.pObject;
  this->Ratio = __that->Ratio;
  this->Depth = __that->Depth;
  this->CharacterId.Id = __that->CharacterId.Id;
  this->ClassName = __that->ClassName;
  this->ClipDepth = __that->ClipDepth;
  this->Flags.Flags = __that->Flags.Flags;
  this->BlendMode = __that->BlendMode;
  return this;
}
