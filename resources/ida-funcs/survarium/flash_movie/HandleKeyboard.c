void __fastcall survarium::flash_movie::HandleKeyboard(
        char modifiers,
        int a2,
        survarium::flash_movie *this,
        survarium::flash_movie::keyb_btn_action action,
        int scan)
{
  char v5; // al
  char v6; // al
  char v7; // al
  int v8; // [esp+8h] [ebp-1Ch] BYREF
  char v9; // [esp+Ch] [ebp-18h]
  int v10; // [esp+10h] [ebp-14h]
  char v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+18h] [ebp-Ch]
  char v13; // [esp+1Ch] [ebp-8h]

  if ( (modifiers & 2) != 0 )
    v5 = (4 * ((modifiers & 4) != 0)) | 2;
  else
    v5 = 4 * ((modifiers & 4) != 0);
  if ( (modifiers & 1) != 0 )
    v6 = v5 | 1;
  else
    v6 = v5 & 0xFE;
  if ( (modifiers & 8) != 0 )
    v7 = v6 | 8;
  else
    v7 = v6 & 0xF7;
  v9 = v7;
  v10 = scan;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v8 = (action != kb_key_down) + 5;
  this->m_movie->HandleEvent(this->m_movie, (const Scaleform::GFx::Event *)&v8);
}
