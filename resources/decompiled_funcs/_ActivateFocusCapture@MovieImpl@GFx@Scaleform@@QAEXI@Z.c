void __thiscall Scaleform::GFx::MovieImpl::ActivateFocusCapture(
        Scaleform::GFx::MovieImpl *this,
        unsigned __int8 controllerIdx)
{
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry v3; // [esp+7Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [esp+88h] [ebp-30h] BYREF

  pfocusInfo.Prev_aRect.x1 = 0.0;
  pfocusInfo.Prev_aRect.y1 = 0.0;
  pfocusInfo.Prev_aRect.x2 = 0.0;
  pfocusInfo.Prev_aRect.y2 = 0.0;
  pfocusInfo.pFocusGroup = 0;
  pfocusInfo.CurFocused.pObject = 0;
  pfocusInfo.CurFocusIdx = -1;
  memset(&pfocusInfo.PrevKeyCode, 0, 13);
  v3.Code = 9;
  v3.KeysState = 0;
  v3.KeyboardIndex = controllerIdx;
  Scaleform::GFx::MovieImpl::ProcessFocusKey(this, KeyDown, &v3, &pfocusInfo);
  Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(this, &pfocusInfo);
  if ( pfocusInfo.CurFocused.pObject )
    Scaleform::RefCountNTSImpl::Release(pfocusInfo.CurFocused.pObject);
}
