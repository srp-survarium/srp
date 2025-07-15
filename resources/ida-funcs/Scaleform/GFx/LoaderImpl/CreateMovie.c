Scaleform::GFx::MovieDefImpl *__thiscall Scaleform::GFx::LoaderImpl::CreateMovie(
        Scaleform::GFx::LoaderImpl *this,
        const __m128i *pfilename,
        unsigned int loadConstants,
        unsigned int memoryArena)
{
  Scaleform::GFx::LoadStates *v5; // eax
  Scaleform::GFx::LoadStates *v6; // eax
  Scaleform::GFx::LoadStates *v7; // esi
  Scaleform::GFx::MovieDefImpl *v9; // edi
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+8h] [ebp-Ch] BYREF

  v5 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
  if ( v5 )
  {
    Scaleform::GFx::LoadStates::LoadStates(v5, (Scaleform::GFx::Resource *)this, 0, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (loadConstants & 0x40) != 0 )
    v7->ThreadedLoading = 1;
  if ( v7->pWeakResourceLib.pObject )
  {
    loc.Use = File_Regular;
    Scaleform::String::String(&loc.FileName, pfilename);
    Scaleform::String::String(&loc.ParentPath);
    v9 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v7, &loc, loadConstants, 0, memoryArena);
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
    return v9;
  }
  else
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
    return 0;
  }
}
