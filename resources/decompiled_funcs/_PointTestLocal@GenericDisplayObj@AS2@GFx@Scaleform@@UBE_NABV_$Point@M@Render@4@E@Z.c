int __thiscall Scaleform::GFx::AS2::GenericDisplayObj::PointTestLocal(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        const Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  return ((int (__thiscall *)(Scaleform::GFx::ShapeBaseCharacterDef *, const Scaleform::Render::Point<float> *, int, Scaleform::GFx::AS2::GenericDisplayObj *))this->pDef.pObject->DefPointTestLocal)(
           this->pDef.pObject,
           pt,
           hitTestMask & 1,
           this);
}
