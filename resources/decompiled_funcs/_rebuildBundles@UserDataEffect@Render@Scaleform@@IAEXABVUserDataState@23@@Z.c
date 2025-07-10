void __thiscall Scaleform::Render::UserDataEffect::rebuildBundles(
        Scaleform::Render::UserDataEffect *this,
        const Scaleform::Render::UserDataState *state)
{
  Scaleform::Render::SortKeyInterface **v3; // eax
  Scaleform::Render::SortKeyInterface **v4; // edi
  Scaleform::Render::SortKeyInterface *pImpl; // ecx
  Scaleform::Render::SortKey v6; // [esp+8h] [ebp-8h] BYREF

  Scaleform::Render::SortKey::SortKey(
    &v6,
    SortKey_UserDataStart,
    (Scaleform::Render::UserDataState::Data *)state->pData);
  v4 = v3;
  ((void (__stdcall *)(Scaleform::Render::SortKeyInterface *))(*v3)->AddRef)(v3[1]);
  this->StartEntry.Key.pImpl->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = *v4;
  pImpl = v6.pImpl;
  this->StartEntry.Key.Data = v4[1];
  pImpl->Release(pImpl, v6.Data);
}
