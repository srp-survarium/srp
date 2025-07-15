void __usercall vostok::render::render_surface::render_surface(
        vostok::render::render_surface *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = &stru_962594.m_declarations;
  *(_QWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 80) = a2 + 148;
  *(_DWORD *)(a2 + 72) = a2 + 84;
  *(_DWORD *)(a2 + 76) = a2 + 84;
  *(_BYTE *)(a2 + 84) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = 1176256512;
}
