FrameInfo *__cdecl _CreateFrameInfo(FrameInfo *pFrameInfo, void *pExceptionObject)
{
  pFrameInfo->pExceptionObject = pExceptionObject;
  pFrameInfo->pNext = (FrameInfo *)_getptd()->_pFrameInfoChain;
  _getptd()->_pFrameInfoChain = pFrameInfo;
  return pFrameInfo;
}
