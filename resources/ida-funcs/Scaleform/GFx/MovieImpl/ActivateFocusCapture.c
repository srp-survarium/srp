void __thiscall Scaleform::GFx::MovieImpl::ActivateFocusCapture(
        Scaleform::GFx::MovieImpl *this,
        unsigned __int8 controllerIdx)
{
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry keyEntry; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [esp+1Ch] [ebp-30h] BYREF

  pfocusInfo.Prev_aRect.x1 = 0.0;
  pfocusInfo.Prev_aRect.y1 = 0.0;
  pfocusInfo.Prev_aRect.x2 = 0.0;
  pfocusInfo.Prev_aRect.y2 = 0.0;
  pfocusInfo.pFocusGroup = 0;
  pfocusInfo.CurFocused.pObject = 0;
  pfocusInfo.CurFocusIdx = -1;
  memset(&pfocusInfo.PrevKeyCode, 0, 13);
  keyEntry.Code = 9;
  keyEntry.KeysState = 0;
  keyEntry.KeyboardIndex = controllerIdx;
  Scaleform::GFx::MovieImpl::ProcessFocusKey(this, KeyDown, &keyEntry, &pfocusInfo);
  Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(this, (Scaleform::Ptr<Scaleform::GFx::Sprite>)&pfocusInfo);
  if ( pfocusInfo.CurFocused.pObject )
    Scaleform::RefCountNTSImpl::Release(pfocusInfo.CurFocused.pObject);
}
