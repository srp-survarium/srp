void __thiscall Scaleform::GFx::AS3::Abc::File::~File(Scaleform::GFx::AS3::Abc::File *this)
{
  volatile LONG *v2; // edi

  this->__vftable = (Scaleform::GFx::AS3::Abc::File_vtbl *)&Scaleform::GFx::AS3::Abc::File::`vftable';
  Scaleform::GFx::AS3::Abc::MethodBodyTable::~MethodBodyTable(&this->MethodBodies);
  Scaleform::GFx::AS3::Abc::ScriptTable::~ScriptTable(&this->Scripts);
  Scaleform::GFx::AS3::Abc::ClassTable::~ClassTable(&this->AS3_Classes);
  Scaleform::GFx::AS3::Abc::TraitTable::~TraitTable(&this->Traits);
  Scaleform::GFx::AS3::Abc::MetadataTable::~MetadataTable(&this->Metadata);
  Scaleform::GFx::AS3::Abc::MethodTable::~MethodTable(&this->Methods);
  Scaleform::GFx::AS3::Abc::ConstPool::~ConstPool(&this->Const_Pool);
  v2 = (volatile LONG *)(this->Source.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->Scaleform::RefCountImpl);
}
