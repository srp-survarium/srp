void __thiscall Scaleform::GFx::CharPosInfo::CharPosInfo(
        Scaleform::GFx::CharPosInfo *this,
        const Scaleform::GFx::CharPosInfo *__that)
{
  Scaleform::Render::FilterSet *pObject; // ecx

  qmemcpy((void *)this, __that, 0x40u);
  pObject = __that->pFilters.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
  this->pFilters.pObject = __that->pFilters.pObject;
  this->Ratio = __that->Ratio;
  this->Depth = __that->Depth;
  this->CharacterId.Id = __that->CharacterId.Id;
  this->ClassName = __that->ClassName;
  this->ClipDepth = __that->ClipDepth;
  this->Flags.Flags = __that->Flags.Flags;
  this->BlendMode = __that->BlendMode;
}


void __thiscall Scaleform::GFx::CharPosInfo::CharPosInfo(
        Scaleform::GFx::CharPosInfo *this,
        Scaleform::GFx::ResourceId chId,
        int depth,
        bool hasCxform,
        const Scaleform::Render::Cxform *cxform,
        bool hasMatrix,
        const Scaleform::Render::Matrix2x4<float> *matrix,
        const char *className,
        float ratio,
        unsigned __int16 clipDepth,
        bool hasBlendMode,
        Scaleform::Render::BlendMode blend)
{
  qmemcpy((void *)this, cxform, 0x20u);
  this->pFilters.pObject = 0;
  this->Matrix_1 = *matrix;
  this->CharacterId = chId;
  this->Flags.Flags = 0;
  this->Ratio = ratio;
  if ( hasMatrix )
    this->Flags.Flags |= 4u;
  if ( hasCxform )
    this->Flags.Flags |= 8u;
  if ( hasBlendMode )
    this->Flags.Flags |= 0x80u;
  this->Depth = depth;
  this->CharacterId = chId;
  this->ClipDepth = clipDepth;
  this->BlendMode = blend;
  this->ClassName = className;
}


void __thiscall Scaleform::GFx::CharPosInfo::CharPosInfo(Scaleform::GFx::CharPosInfo *this)
{
  Scaleform::Render::Cxform::Cxform(&this->ColorTransform);
  this->Matrix_1.M[0][0] = 1.0;
  this->pFilters.pObject = 0;
  this->Matrix_1.M[0][1] = 0.0;
  this->Matrix_1.M[0][2] = 0.0;
  this->Matrix_1.M[0][3] = 0.0;
  this->Matrix_1.M[1][0] = 0.0;
  this->Matrix_1.M[1][2] = 0.0;
  this->Matrix_1.M[1][3] = 0.0;
  this->Matrix_1.M[1][1] = 1.0;
  this->CharacterId.Id = 0x40000;
  this->Flags.Flags = 0;
  this->Depth = 0;
  this->Ratio = 0.0;
  this->BlendMode = 0;
  this->ClassName = 0;
  this->ClipDepth = 0;
}
