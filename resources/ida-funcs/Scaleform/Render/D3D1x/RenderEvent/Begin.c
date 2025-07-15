void __userpurge Scaleform::Render::D3D1x::RenderEvent::Begin(
        Scaleform::Render::D3D1x::RenderEvent *this@<ecx>,
        int a2@<edi>,
        Scaleform::String eventName)
{
  wchar_t pwcs[256]; // [esp+0h] [ebp-204h] BYREF
  unsigned int pConvertedChars; // [esp+200h] [ebp-4h] BYREF

  mbstowcs_s(a2, &pConvertedChars, pwcs, 0x100u, (char *)((eventName.HeapTypeBits & 0xFFFFFFFC) + 8), 0x100u);
  if ( Scaleform::Render::D3D1x::RenderEvent::BeginEventFn )
    Scaleform::Render::D3D1x::RenderEvent::BeginEventFn(0xFF000000, pwcs);
  Scaleform::String::DataDesc::Release((Scaleform::String::DataDesc *)(eventName.HeapTypeBits & 0xFFFFFFFC));
}
