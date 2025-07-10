void __stdcall Scaleform::GFx::PlaceObject2Tag::SetEventHandlersPtr(
        unsigned __int8 *pdata,
        Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peh)
{
  *(_DWORD *)(pdata + 1) = peh;
}
