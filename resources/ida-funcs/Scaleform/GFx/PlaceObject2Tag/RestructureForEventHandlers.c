void __stdcall Scaleform::GFx::PlaceObject2Tag::RestructureForEventHandlers(unsigned __int8 *pdata)
{
  *pdata = pdata[4];
  *(_DWORD *)(pdata + 1) = 0;
}
