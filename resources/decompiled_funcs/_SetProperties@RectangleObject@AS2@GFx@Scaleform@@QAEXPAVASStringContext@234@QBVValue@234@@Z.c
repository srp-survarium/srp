void __thiscall Scaleform::GFx::AS2::RectangleObject::SetProperties(
        Scaleform::GFx::AS2::RectangleObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, "x", params);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "y", params + 1);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "width", params + 2);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v3, psc, "height", params + 3);
}
