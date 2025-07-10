char __thiscall SpeedTree::CSharedHeapBlock::Unlock(SpeedTree::CSharedHeapBlock *this)
{
  char v2; // [esp+Bh] [ebp-1h]

  v2 = 0;
  if ( *((_BYTE *)this + 272) )
  {
    *((_BYTE *)this + 272) = 0;
    *((_DWORD *)this + 3) = 0;
    *((_BYTE *)this + 16) = 0;
    return 1;
  }
  else
  {
    SpeedTree::CCore::SetError("CSharedHeapBlock::Unlock() called when buffer was not locked");
  }
  return v2;
}
