void __thiscall Scaleform::GFx::MoviePreloadTask::Execute(Scaleform::GFx::MoviePreloadTask *this)
{
  Scaleform::String *p_UrlStrGfx; // edi
  Scaleform::GFx::MovieDefImpl *v3; // eax
  Scaleform::GFx::MovieDefImpl *pObject; // ecx
  Scaleform::GFx::MovieDefImpl *v5; // edi
  Scaleform::GFx::MovieDefImpl *v6; // eax
  Scaleform::GFx::MovieDefImpl *v7; // ecx
  Scaleform::GFx::MovieDefImpl *v8; // edi
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+8h] [ebp-Ch] BYREF

  p_UrlStrGfx = &this->UrlStrGfx;
  if ( Scaleform::String::GetLength(&this->UrlStrGfx) )
  {
    loc.Use = File_LoadMovie;
    Scaleform::String::String(&loc.FileName, p_UrlStrGfx);
    Scaleform::String::String(&loc.ParentPath, &this->Level0Path);
    v3 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(this->pLoadStates.pObject, &loc, this->LoadFlags, 0, 0);
    pObject = this->pDefImpl.pObject;
    v5 = v3;
    if ( pObject )
      Scaleform::GFx::Resource::Release(pObject);
    this->pDefImpl.pObject = v5;
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
  }
  if ( !this->pDefImpl.pObject )
  {
    loc.Use = File_LoadMovie;
    Scaleform::String::String(&loc.FileName, &this->Url);
    Scaleform::String::String(&loc.ParentPath, &this->Level0Path);
    v6 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(this->pLoadStates.pObject, &loc, this->LoadFlags, 0, 0);
    v7 = this->pDefImpl.pObject;
    v8 = v6;
    if ( v7 )
      Scaleform::GFx::Resource::Release(v7);
    this->pDefImpl.pObject = v8;
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
  }
  InterlockedExchange((volatile LONG *)&this->Done, 1);
}
