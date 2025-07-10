void __usercall vostok::render::texture_storage::texture_storage(
        vostok::render::texture_storage *this@<ecx>,
        int a2@<eax>)
{
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_BYTE *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = a2;
  *(_DWORD *)(a2 + 12) = a2;
  *(_DWORD *)(a2 + 16) = 0;
  *(_BYTE *)(a2 + 20) = HIBYTE(this);
  *(_BYTE *)(a2 + 24) = 0;
}
