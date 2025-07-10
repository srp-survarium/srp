bool __thiscall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::File *obj)
{
  unsigned __int16 v3; // ax

  Scaleform::GFx::AS3::Abc::File::Clear(obj);
  obj->MinorVersion = Scaleform::GFx::AS3::Abc::Read16<unsigned char>(&this->CP);
  v3 = Scaleform::GFx::AS3::Abc::Read16<unsigned char>(&this->CP);
  obj->MajorVersion = v3;
  return v3 == 46
      && obj->MinorVersion == 16
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Const_Pool)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->Methods)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           &obj->Const_Pool,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->Metadata)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           &obj->Traits,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->AS3_Classes)
      && Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           &obj->Traits,
           (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)&obj->Scripts)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Traits, &obj->Methods, (int)&obj->MethodBodies);
}
