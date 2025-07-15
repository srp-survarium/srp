void __cdecl Scaleform::Waitable_SingleWaitHandler(Scaleform::Event **hdata)
{
  if ( (*hdata)->IsSignaled(*hdata) )
    Scaleform::Event::PulseEvent(hdata[1]);
}
