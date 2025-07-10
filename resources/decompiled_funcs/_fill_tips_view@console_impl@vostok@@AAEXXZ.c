void __userpurge vostok::console_impl::fill_tips_view(
        vostok::console_impl *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::console_impl *thisa,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        void *a11)
{
  int v11; // eax
  int v12; // esi
  const void *v13; // edi
  int v14; // esi
  float v15; // xmm0_4
  int v16; // eax
  void (__thiscall ***v17)(_DWORD, _DWORD *); // eax
  int v18; // eax
  void (__thiscall **p_add_child)(_DWORD, int); // edi
  int v20; // eax
  int v21; // eax
  int v22; // eax
  float v23; // [esp+34h] [ebp-1Ch]
  unsigned int line_size; // [esp+38h] [ebp-18h]
  unsigned int line_size_4; // [esp+3Ch] [ebp-14h]
  vostok::ui::window *v26; // [esp+40h] [ebp-10h]
  float v27[2]; // [esp+44h] [ebp-Ch] BYREF
  _DWORD var4[2]; // [esp+4Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+54h] [ebp+4h] BYREF

  v11 = ((int (__thiscall *)(vostok::ui::image *, int, int, int))thisa->m_ui_tips_view->w)(
          thisa->m_ui_tips_view,
          a3,
          a4,
          a2);
  (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 72))(v11);
  line_size = 0;
  v12 = thisa->m_tips._M_impl._M_finish - thisa->m_tips._M_impl._M_start;
  line_size_4 = v12;
  if ( v12 )
  {
    do
    {
      v13 = thisa->m_tips._M_impl._M_start[line_size];
      v14 = (int)thisa->m_ui_world->create_text(thisa->m_ui_world);
      (*(void (__thiscall **)(int, const void *))(*(_DWORD *)v14 + 8))(v14, v13);
      (**(void (__thiscall ***)(int, _DWORD))v14)(v14, 0);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v14 + 20))(v14, 0);
      v15 = *(float *)(*(int (__thiscall **)(int, void **))(*(_DWORD *)v14 + 24))(v14, &retaddr);
      if ( v27[0] <= v15 )
        v27[0] = v15;
      v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 28))(v14);
      (*(void (__thiscall **)(int, float *))(*(_DWORD *)v16 + 8))(v16, v27);
      v17 = (void (__thiscall ***)(_DWORD, _DWORD *))(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 28))(v14);
      var4[0] = 0;
      *(float *)&var4[1] = v23;
      (**v17)(v17, var4);
      v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 28))(v14);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 16))(v18, 1);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 4))(v14, -16711936);
      v26 = thisa->m_ui_tips_view->w(thisa->m_ui_tips_view);
      p_add_child = (void (__thiscall **)(_DWORD, int))&v26->add_child;
      v20 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v14 + 28))(v14, 1);
      (*p_add_child)(LODWORD(v27[0]), v20);
      v23 = v27[1] + v23;
      ++line_size;
    }
    while ( line_size < line_size_4 );
    v12 = line_size_4;
  }
  v21 = (int)thisa->m_ui_tips_view->w(thisa->m_ui_tips_view);
  a10 = a8;
  a11 = retaddr;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v21 + 8))(v21, &a10);
  v22 = (int)thisa->m_ui_tips_view->w(thisa->m_ui_tips_view);
  (*(void (__thiscall **)(int, bool))(*(_DWORD *)v22 + 16))(v22, v12 != 0);
}
