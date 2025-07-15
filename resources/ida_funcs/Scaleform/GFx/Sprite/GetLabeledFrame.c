int __thiscall Scaleform::GFx::Sprite::GetLabeledFrame(
        Scaleform::GFx::Sprite *this,
        const char *label,
        unsigned int *frameNumber,
        int translateNumbers)
{
  return ((int (__thiscall *)(Scaleform::GFx::TimelineDef *, const char *, unsigned int *, int))this->pDef.pObject->GetLabeledFrame)(
           this->pDef.pObject,
           label,
           frameNumber,
           translateNumbers);
}
