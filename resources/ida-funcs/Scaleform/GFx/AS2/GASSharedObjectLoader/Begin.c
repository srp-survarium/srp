void __thiscall Scaleform::GFx::AS2::GASSharedObjectLoader::Begin(Scaleform::GFx::AS3::ASSharedObjectLoader *this)
{
  Scaleform::Array<Scaleform::GFx::AS3::Instances::fl::Object *,2,Scaleform::ArrayDefaultPolicy> *p_ObjectStack; // esi
  unsigned int v3; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v4; // eax

  p_ObjectStack = &this->ObjectStack;
  if ( this->ObjectStack.Data.Size )
  {
    if ( (this->ObjectStack.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( p_ObjectStack->Data.Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_ObjectStack->Data.Data);
        p_ObjectStack->Data.Data = 0;
      }
      p_ObjectStack->Data.Policy.Capacity = 0;
    }
  }
  else if ( !this->ObjectStack.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->ObjectStack.Data,
      &this->ObjectStack,
      0);
  }
  p_ObjectStack->Data.Size = 0;
  v3 = p_ObjectStack->Data.Size + 1;
  if ( v3 >= p_ObjectStack->Data.Size )
  {
    if ( v3 >= p_ObjectStack->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_ObjectStack->Data,
        p_ObjectStack,
        v3 + (v3 >> 2));
  }
  else if ( v3 < p_ObjectStack->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_ObjectStack->Data,
      p_ObjectStack,
      p_ObjectStack->Data.Size + 1);
  }
  v4 = &p_ObjectStack->Data.Data[v3 - 1];
  p_ObjectStack->Data.Size = v3;
  if ( v4 )
    *v4 = this->pData;
}
