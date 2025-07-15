void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3splice(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Object *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Object *v4; // ebx
  Scaleform::GFx::AS3::Value *v5; // ebp
  unsigned int v6; // eax
  bool v8; // sf
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // esi
  Scaleform::GFx::AS3::Object *v10; // edi
  Scaleform::GFx::AS3::Impl::SparseArray *v11; // eax
  unsigned int Length; // eax
  int startIndex; // [esp+Ch] [ebp-4h] BYREF

  v4 = argc;
  v5 = argv;
  v6 = 0;
  startIndex = 0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &startIndex)->Result )
      return;
    v6 = startIndex;
    if ( startIndex < 0 )
    {
      v8 = (signed int)(this->SA.Length + startIndex) < 0;
      v6 = this->SA.Length + startIndex;
      startIndex = v6;
      if ( v8 )
      {
        v6 = 0;
        startIndex = 0;
      }
    }
  }
  p_SA = &this->SA;
  argv = (Scaleform::GFx::AS3::Value *)this->SA.Length;
  if ( (unsigned int)v4 <= 1 )
  {
    argv = (Scaleform::GFx::AS3::Value *)((char *)argv - v6);
  }
  else if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(
               v5 + 1,
               (Scaleform::GFx::AS3::CheckResult *)&argc,
               (unsigned int *)&argv)->Result )
  {
    return;
  }
  Scaleform::GFx::AS3::InstanceTraits::MakeInstance<Scaleform::GFx::AS3::InstanceTraits::fl::Array>(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&argc,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  v10 = argc;
  Scaleform::GFx::AS3::Value::Pick(result, argc);
  if ( v10 )
    v11 = (Scaleform::GFx::AS3::Impl::SparseArray *)&v10[1];
  else
    v11 = 0;
  Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(p_SA, startIndex, (unsigned int)argv, v11);
  if ( (unsigned int)v4 > 2 )
  {
    Length = startIndex;
    if ( (signed int)p_SA->Length < startIndex )
    {
      Length = p_SA->Length;
      startIndex = p_SA->Length;
    }
    Scaleform::GFx::AS3::Impl::SparseArray::Insert(p_SA, Length, (unsigned int)&v4[-1].pUserDataHolder + 2, v5 + 2);
  }
}
