void __userpurge survarium::flash_text::set_color(
        survarium::flash_text *this@<esi>,
        unsigned __int8 r@<cl>,
        unsigned __int8 g@<dl>,
        unsigned __int8 b,
        unsigned __int8 a)
{
  int v5; // [esp-Ch] [ebp-Ch]

  BYTE1(v5) = g;
  BYTE2(v5) = r;
  HIBYTE(v5) = a;
  LOBYTE(v5) = b;
  ((void (__thiscall *)(Scaleform::GFx::DrawText *, int, _DWORD, int))this->text_impl->SetColor)(
    this->text_impl,
    v5,
    0,
    -1);
  this->owner->need_capture = 1;
}
