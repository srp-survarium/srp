void __userpurge boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this@<ecx>,
        int a2@<eax>,
        unsigned int index1,
        unsigned int index2)
{
  int v4; // edx
  unsigned int v5; // ecx
  int *v6; // esi
  _DWORD *v7; // edi
  int v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h]
  int v11; // [esp+18h] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 12);
  v5 = 16 * index1;
  v6 = (int *)(16 * index1 + v4);
  v8 = *v6++;
  v9 = *v6++;
  v10 = *v6;
  v11 = v6[1];
  *(_DWORD *)(v4 + v5) = *(_DWORD *)(16 * index2 + v4);
  *(_DWORD *)(v4 + v5 + 4) = *(_DWORD *)(16 * index2 + v4 + 4);
  *(_DWORD *)(v4 + v5 + 8) = *(_DWORD *)(16 * index2 + v4 + 8);
  *(_DWORD *)(v4 + v5 + 12) = *(_DWORD *)(16 * index2 + v4 + 12);
  v7 = (_DWORD *)(16 * index2 + *(_DWORD *)(a2 + 12));
  *v7++ = v8;
  *v7++ = v9;
  *v7 = v10;
  v7[1] = v11;
  *(_DWORD *)(*(_DWORD *)(v5 + *(_DWORD *)(a2 + 12) + 8) + 8) = index1;
  *(_DWORD *)(*(_DWORD *)(16 * index2 + *(_DWORD *)(a2 + 12) + 8) + 8) = index2;
}
