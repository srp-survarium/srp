void __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(Scaleform::GFx::AS3::ClassTraits::Traits *this)
{
  const Scaleform::GFx::AS3::ThunkInfo *v2; // esi
  int v3; // ebx
  const Scaleform::GFx::AS3::ThunkInfo *v4; // esi
  int v5; // ebx
  Scaleform::GFx::AS3::TypeInfo TNone; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::ClassInfo CNone; // [esp+20h] [ebp-1Ch] BYREF

  v2 = ti;
  v3 = 3;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ObjectCI, v2++);
    --v3;
  }
  while ( v3 );
  TNone.Name = uri;
  TNone.PkgName = uri;
  TNone.Flags = 0;
  TNone.Parent = 0;
  TNone.Implements = 0;
  CNone.Type = &TNone;
  memset(&CNone.Factory, 0, 24);
  v4 = f_4;
  v5 = 3;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, (Scaleform::GFx::ASStringNode *)&CNone, v4++);
    --v5;
  }
  while ( v5 );
  this->FirstOwnSlotInd.Index += 6;
}
