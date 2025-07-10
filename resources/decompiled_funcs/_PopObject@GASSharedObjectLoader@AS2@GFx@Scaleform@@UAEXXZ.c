void __thiscall Scaleform::GFx::AS2::GASSharedObjectLoader::PopObject(Scaleform::GFx::AS2::GASSharedObjectLoader *this)
{
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *p_ObjectStack; // esi
  unsigned int v4; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // eax

  Size = this->ObjectStack.Data.Size;
  p_ObjectStack = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ObjectStack;
  v4 = Size - 1;
  if ( Size )
  {
    if ( v4 < this->ObjectStack.Data.Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ObjectStack,
        p_ObjectStack,
        v4);
  }
  else if ( v4 >= this->ObjectStack.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ObjectStack,
      p_ObjectStack,
      v4 + (v4 >> 2));
  }
  p_ObjectStack->Size = v4;
  v5 = p_ObjectStack->Data[v4 - 1];
  this->bArrayIsTop = (*(int (__thiscall **)(unsigned int *))(v5->RefCount + 8))(&v5->RefCount) == 7;
}
