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
