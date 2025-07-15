char __userpurge survarium::swf_input_translator::process_mouse_btn@<al>(
        survarium::swf_input_translator *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>,
        vostok::input::enum_mouse_key_action action,
        enum vostok::input::mouse_button y,
        enum vostok::input::enum_mouse_key_action movie,
        float a7,
        float a8,
        struct survarium::flash_movie *a9)
{
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v15; // [esp-4h] [ebp-20h]
  int v16; // [esp+0h] [ebp-1Ch] BYREF
  char v17; // [esp+4h] [ebp-18h]
  int v18; // [esp+8h] [ebp-14h]
  enum vostok::input::mouse_button v19; // [esp+Ch] [ebp-10h]
  int v20; // [esp+10h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-8h]
  int v22; // [esp+18h] [ebp-4h]

  v9 = 0;
  v10 = a2 - 337;
  if ( v10 )
  {
    v11 = v10 - 1;
    if ( v11 )
    {
      if ( v11 == 1 )
        v9 = 2;
    }
    else
    {
      v9 = 1;
    }
  }
  else
  {
    v9 = 0;
  }
  v12 = 0;
  if ( action == ms_key_down )
  {
    v15 = 2;
LABEL_11:
    v12 = v15;
    goto LABEL_12;
  }
  if ( action == ms_key_up )
  {
    v15 = 3;
    goto LABEL_11;
  }
LABEL_12:
  v18 = a3;
  v16 = v12;
  v17 = 0;
  v21 = v9;
  v13 = *(_DWORD *)(movie + 4);
  v19 = y;
  v22 = 0;
  v20 = 0;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v13 + 136))(v13, &v16);
  return 1;
}
