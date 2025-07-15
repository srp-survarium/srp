void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getCharBoundaries(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        unsigned int charIndex)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  double v5; // st5
  double v6; // st5
  double v7; // st6
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  Scaleform::GFx::AS3::Value *v13; // esi
  int i; // edi
  unsigned int Flags; // eax
  float v16; // [esp+94h] [ebp-54h]
  float v17; // [esp+94h] [ebp-54h]
  float v18; // [esp+94h] [ebp-54h]
  float v19; // [esp+94h] [ebp-54h]
  float v20; // [esp+94h] [ebp-54h]
  float v21; // [esp+94h] [ebp-54h]
  float v22; // [esp+94h] [ebp-54h]
  Scaleform::Render::Rect<float> pCharRect; // [esp+98h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value v24; // [esp+A8h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v25; // [esp+B8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v26; // [esp+C8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v27; // [esp+D8h] [ebp-10h] BYREF
  char vars0; // [esp+E8h] [ebp+0h] BYREF

  pCharRect.x1 = 0.0;
  pCharRect.y1 = 0.0;
  pObject = this->pDispObj.pObject;
  v16 = 0.0 + 0.0;
  pCharRect.x2 = v16;
  pCharRect.y2 = v16;
  if ( Scaleform::Render::Text::DocView::GetCharBoundaries(
         (Scaleform::Render::Text::DocView *)pObject[1].pRenNode.pObject,
         &pCharRect,
         charIndex) )
  {
    v24.Bonus.pWeakProxy = 0;
    v25.Flags = 0;
    v25.Bonus.pWeakProxy = 0;
    v26.Flags = 0;
    v17 = pCharRect.x1 * 0.05000000074505806;
    v26.Bonus.pWeakProxy = 0;
    v27.Flags = 0;
    v5 = v17;
    v27.Bonus.pWeakProxy = 0;
    if ( v17 <= 0.0 )
      v6 = v5 - 0.5;
    else
      v6 = v5 + 0.5;
    v24.Flags = 4;
    v24.value.VNumber = (double)(int)v6;
    v18 = 0.05000000074505806 * pCharRect.y1;
    v7 = v18;
    if ( v18 <= 0.0 )
      v8 = v7 - 0.5;
    else
      v8 = v7 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&v25, (double)(int)v8);
    v19 = pCharRect.x2 - pCharRect.x1;
    v20 = v19 * 0.05000000074505806;
    v9 = v20;
    if ( v20 <= 0.0 )
      v10 = v9 - 0.5;
    else
      v10 = v9 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&v26, (double)(int)v10);
    v21 = pCharRect.y2 - pCharRect.y1;
    v22 = v21 * 0.05000000074505806;
    v11 = v22;
    if ( v22 <= 0.0 )
      v12 = v11 - 0.5;
    else
      v12 = v11 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&v27, (double)(int)v12);
    Scaleform::GFx::AS3::ASVM::_constructInstance(
      (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
      result,
      (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.Policy.Capacity,
      4u,
      &v24);
    v13 = (Scaleform::GFx::AS3::Value *)&vars0;
    for ( i = 3; i >= 0; --i )
    {
      Flags = v13[-1].Flags;
      --v13;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v13);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v13);
      }
    }
  }
}
