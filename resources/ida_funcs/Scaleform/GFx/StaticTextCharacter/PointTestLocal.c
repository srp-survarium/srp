int __thiscall Scaleform::GFx::StaticTextCharacter::PointTestLocal(
        Scaleform::GFx::StaticTextCharacter *this,
        const Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  return ((int (__thiscall *)(Scaleform::GFx::StaticTextDef *, const Scaleform::Render::Point<float> *, int, Scaleform::GFx::StaticTextCharacter *))this->pDef.pObject->DefPointTestLocal)(
           this->pDef.pObject,
           pt,
           hitTestMask & 1,
           this);
}
