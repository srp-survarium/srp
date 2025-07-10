char __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::Instance::Interfaces *obj)
{
  const unsigned __int8 **p_CP; // ebp
  unsigned int v3; // eax
  int v5; // esi
  int v6; // eax
  unsigned int v7; // esi
  int v8; // ebx
  bool v9; // zf
  int *Data; // edx
  Scaleform::GFx::AS3::Abc::Instance::Interfaces *obja; // [esp+10h] [ebp+4h]

  p_CP = &this->CP;
  v3 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(&this->CP);
  v5 = v3;
  if ( v3 > obj->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->info.Data,
      obj,
      v3);
  if ( v5 > 0 )
  {
    obja = (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)v5;
    do
    {
      v6 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(p_CP);
      v7 = obj->info.Data.Size + 1;
      v8 = v6;
      if ( v7 >= obj->info.Data.Size )
      {
        if ( v7 >= obj->info.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &obj->info.Data,
            obj,
            v7 + (v7 >> 2));
      }
      else if ( v7 < obj->info.Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &obj->info.Data,
          obj,
          obj->info.Data.Size + 1);
      }
      v9 = obja == (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)1;
      obja = (Scaleform::GFx::AS3::Abc::Instance::Interfaces *)((char *)obja - 1);
      Data = obj->info.Data.Data;
      obj->info.Data.Size = v7;
      Data[v7 - 1] = v8;
    }
    while ( !v9 );
  }
  return 1;
}
