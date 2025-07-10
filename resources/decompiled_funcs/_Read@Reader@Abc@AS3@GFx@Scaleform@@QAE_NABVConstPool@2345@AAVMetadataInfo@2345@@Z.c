char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        const Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::GFx::AS3::Abc::MetadataInfo *obj)
{
  unsigned int v4; // eax
  int v5; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338,Scaleform::ArrayDefaultPolicy> *p_Items; // edi
  unsigned int v7; // esi
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v9; // eax
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v10; // esi
  int v11; // esi
  int v12; // ebp
  int count[2]; // [esp+8h] [ebp-8h] BYREF
  const unsigned __int8 **cpa; // [esp+14h] [ebp+4h]
  Scaleform::GFx::AS3::Abc::MetadataInfo *obja; // [esp+18h] [ebp+8h]

  count[0] = 0;
  count[1] = 0;
  if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->Name, (const Scaleform::StringDataPtr *)count) )
    return 0;
  cpa = &this->CP;
  v4 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v5 = v4;
  p_Items = &obj->Items;
  count[0] = v4;
  if ( v4 > obj->Items.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_Items->Data,
      p_Items,
      v4);
  if ( v5 > 0 )
  {
    obja = (Scaleform::GFx::AS3::Abc::MetadataInfo *)v5;
    do
    {
      v7 = p_Items->Data.Size + 1;
      if ( v7 >= p_Items->Data.Size )
      {
        if ( v7 >= p_Items->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_Items->Data,
            p_Items,
            v7 + (v7 >> 2));
      }
      else if ( v7 < p_Items->Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &p_Items->Data,
          p_Items,
          p_Items->Data.Size + 1);
      }
      v9 = &p_Items->Data.Data[v7 - 1];
      p_Items->Data.Size = v7;
      if ( v9 )
      {
        v9->KeyInd = 0;
        v9->ValueInd = 0;
      }
      v10 = &p_Items->Data.Data[p_Items->Data.Size - 1];
      v10->KeyInd = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cpa);
      obja = (Scaleform::GFx::AS3::Abc::MetadataInfo *)((char *)obja - 1);
    }
    while ( obja );
  }
  v11 = 0;
  if ( v5 > 0 )
  {
    do
    {
      v12 = (int)&p_Items->Data.Data[v11];
      *(_DWORD *)(v12 + 4) = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(cpa);
      ++v11;
    }
    while ( v11 < count[0] );
  }
  return 1;
}
