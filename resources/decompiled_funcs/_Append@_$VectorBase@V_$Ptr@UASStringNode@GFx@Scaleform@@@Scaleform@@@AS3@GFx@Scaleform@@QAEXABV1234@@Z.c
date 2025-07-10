void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Append(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        const Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *other)
{
  const Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *v3; // ecx
  unsigned int v4; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // ebx
  int v7; // ebp
  unsigned int Size; // eax
  unsigned int v9; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v10; // eax
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v11; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-5h] BYREF
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v3 = other;
    v4 = 0;
    i = 0;
    if ( other->ValueA.Data.Size )
    {
      p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
      do
      {
        Data = p_ValueA[1].Data;
        v7 = (int)&v3->ValueA.Data.Data[v4];
        Size = p_ValueA->Size;
        v9 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v9 >= p_ValueA->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              Data,
              v9 + (v9 >> 2));
        }
        else
        {
          Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::DestructArray(
            (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&p_ValueA->Data[Size + 1],
            0xFFFFFFFF);
          if ( v9 < p_ValueA->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ValueA,
              Data,
              v9);
        }
        v10 = p_ValueA->Data;
        p_ValueA->Size = v9;
        v11 = &v10[v9 - 1];
        if ( v11 )
        {
          if ( *(_DWORD *)v7 )
            ++*(_DWORD *)(*(_DWORD *)v7 + 12);
          *v11 = *(const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **)v7;
        }
        v3 = other;
        v4 = i + 1;
        i = v4;
      }
      while ( v4 < other->ValueA.Data.Size );
    }
  }
}
