void __thiscall Scaleform::GFx::ZlibSupport::CreateZlibFile(
        Scaleform::GFx::ZlibSupport *this,
        Scaleform::GFx::Resource *in)
{
  Scaleform::GFx::ZLibFile *v2; // eax
  int v3; // [esp+4h] [ebp-4h] BYREF

  v3 = 2;
  v2 = (Scaleform::GFx::ZLibFile *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                     Scaleform::Memory::pGlobalHeap,
                                     this,
                                     12,
                                     &v3);
  if ( v2 )
    Scaleform::GFx::ZLibFile::ZLibFile(v2, in);
}
