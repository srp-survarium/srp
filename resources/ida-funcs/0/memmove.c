void __cdecl memmove(int dst, const __m128i *src, unsigned int count)
{
  const __m128i *v3; // esi
  int v4; // edi
  unsigned int v5; // ecx
  char *v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > (unsigned int)src && dst < (unsigned int)src->m128i_u32 + count )
  {
    v6 = &src->m128i_i8[count - 4];
    v7 = count + dst - 4;
    if ( (v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          *(_BYTE *)(v7 + 3) = v6[3];
          break;
        case 2u:
TrailDown2:
          *(_BYTE *)(v7 + 3) = v6[3];
          *(_BYTE *)(v7 + 2) = v6[2];
          break;
        case 3u:
TrailDown3:
          *(_BYTE *)(v7 + 3) = v6[3];
          *(_BYTE *)(v7 + 2) = v6[2];
          *(_BYTE *)(v7 + 1) = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x100 && __sse2_available && (v3 = src, v4 = dst, (dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, count);
  }
  else
  {
    if ( (v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 0029814C case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)(v4 + 4 * v5 - 28) = *((_DWORD *)&v3[-1] + v5 - 3);
UnwindUp6:
        *(_DWORD *)(v4 + 4 * v5 - 24) = *((_DWORD *)&v3[-1] + v5 - 2);
UnwindUp5:
        *(_DWORD *)(v4 + 4 * v5 - 20) = *((_DWORD *)&v3[-1] + v5 - 1);
UnwindUp4:
        *(_DWORD *)(v4 + 4 * v5 - 16) = v3[-1].m128i_i32[v5];
UnwindUp3:
        *(_DWORD *)(v4 + 4 * v5 - 12) = v3->m128i_i32[v5 - 3];
UnwindUp2:
        *(_DWORD *)(v4 + 4 * v5 - 8) = v3->m128i_i32[v5 - 2];
UnwindUp1:
        *(_DWORD *)(v4 + 4 * v5 - 4) = v3->m128i_i32[v5 - 1];
        v3 = (const __m128i *)((char *)v3 + 4 * v5);
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy((void *)v4, v3, 4 * v5);
        v3 = (const __m128i *)((char *)v3 + 4 * v5);
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *(_BYTE *)v4 = v3->m128i_i8[0];
            break;
          case 2u:
TrailUp2:
            *(_BYTE *)v4 = v3->m128i_i8[0];
            *(_BYTE *)(v4 + 1) = v3->m128i_i8[1];
            break;
          case 3u:
TrailUp3:
            *(_BYTE *)v4 = v3->m128i_i8[0];
            *(_BYTE *)(v4 + 1) = v3->m128i_i8[1];
            *(_BYTE *)(v4 + 2) = v3->m128i_i8[2];
            break;
        }
        break;
    }
  }
}
