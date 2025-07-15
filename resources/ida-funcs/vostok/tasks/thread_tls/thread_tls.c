void __usercall vostok::tasks::thread_tls::thread_tls(vostok::tasks::thread_tls *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)(a2 + 64) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 72) = 1;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 176) = 0;
  *(_DWORD *)(a2 + 180) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 216) = 0;
  *(_DWORD *)(a2 + 220) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  *(_DWORD *)(a2 + 228) = 0;
  *(_DWORD *)(a2 + 232) = 1;
  *(_DWORD *)(a2 + 236) = 4;
  *(_DWORD *)(a2 + 240) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 248) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 256) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_BYTE *)(a2 + 308) = 0;
  *(_DWORD *)(a2 + 296) = a2 + 308;
  *(_DWORD *)(a2 + 300) = a2 + 308;
  *(_DWORD *)(a2 + 304) = a2 + 340;
  *(_DWORD *)(a2 + 352) = 0;
}
