void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception>::DestructArray(
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *p,
        unsigned int count)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *i; // esi

  v2 = count;
  for ( i = &p[count - 1]; v2; --v2 )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, i->info.Data.Data);
    --i;
  }
}
