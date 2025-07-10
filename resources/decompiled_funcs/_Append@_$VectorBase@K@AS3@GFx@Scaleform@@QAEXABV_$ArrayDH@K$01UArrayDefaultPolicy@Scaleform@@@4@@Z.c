void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *arr)
{
  unsigned int v4; // ebx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  unsigned int v7; // esi
  unsigned int **v8; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-1h] BYREF
  const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *arra; // [esp+Ch] [ebp+4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v4 = 0;
    if ( arr->Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = p_ValueA[1].Data;
        v7 = p_ValueA->Size + 1;
        arra = (const Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)&arr->Data.Data[v4];
        if ( v7 >= p_ValueA->Size )
        {
          if ( v7 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              Data,
              v7 + (v7 >> 2));
        }
        else if ( v7 < p_ValueA->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_ValueA,
            Data,
            v7);
        }
        v8 = (unsigned int **)&p_ValueA->Data[v7 - 1];
        p_ValueA->Size = v7;
        if ( v8 )
          *v8 = arra->Data.Data;
        ++v4;
      }
      while ( v4 < arr->Data.Size );
    }
  }
}
