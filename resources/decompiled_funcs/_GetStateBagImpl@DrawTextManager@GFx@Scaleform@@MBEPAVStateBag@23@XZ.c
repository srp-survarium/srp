Scaleform::GFx::StateBag *__thiscall Scaleform::GFx::DrawTextManager::GetStateBagImpl(
        Scaleform::GFx::DrawTextManager *this)
{
  int v1; // eax

  v1 = *(_DWORD *)(this->RefCount + 4);
  if ( v1 )
    return (Scaleform::GFx::StateBag *)(v1 + 8);
  else
    return 0;
}
