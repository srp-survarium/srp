BOOL __usercall vostok::ui::ui_text_edit::is_shift_state@<eax>(vostok::ui::ui_text_edit *this@<ecx>, int a2@<eax>)
{
  BOOL result; // eax
  char v3; // al

  switch ( (unsigned int)this )
  {
    case 0u:
      result = (*(_BYTE *)(a2 + 684) & 0x30) != 0;
      break;
    case 1u:
      result = (*(_BYTE *)(a2 + 684) & 3) != 0;
      break;
    case 2u:
      result = (*(_BYTE *)(a2 + 684) & 0xC) != 0;
      break;
    case 3u:
      v3 = *(_BYTE *)(a2 + 684);
      result = (v3 & 3) != 0 && (v3 & 0x30) != 0;
      break;
  }
  return result;
}
