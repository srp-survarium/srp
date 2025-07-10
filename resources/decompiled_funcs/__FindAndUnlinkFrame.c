void __cdecl _FindAndUnlinkFrame(FrameInfo *pFrameInfo)
{
  _DWORD *i; // eax

  if ( pFrameInfo == _getptd()->_pFrameInfoChain )
  {
    _getptd()->_pFrameInfoChain = pFrameInfo->pNext;
  }
  else
  {
    for ( i = _getptd()->_pFrameInfoChain; ; i = (_DWORD *)i[1] )
    {
      if ( !i[1] )
        _inconsistency();
      if ( pFrameInfo == (FrameInfo *)i[1] )
        break;
    }
    i[1] = pFrameInfo->pNext;
  }
}
