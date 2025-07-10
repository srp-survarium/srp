void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyMaskType maskType)
{
  Scaleform::Render::SortKeyInterface *v3; // ecx

  v3 = SortKeyMaskInterfaces[maskType];
  this->Data = (void *)maskType;
  this->pImpl = v3;
  v3->AddRef(v3, (void *)maskType);
}
