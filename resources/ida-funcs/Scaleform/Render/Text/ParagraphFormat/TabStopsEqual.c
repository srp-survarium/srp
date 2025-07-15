bool __thiscall Scaleform::Render::Text::ParagraphFormat::TabStopsEqual(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int *psrcTabStops)
{
  unsigned int *pTabStops; // eax
  unsigned int v4; // ecx
  unsigned int *v5; // edx
  unsigned __int8 *v6; // esi

  pTabStops = this->pTabStops;
  if ( pTabStops == psrcTabStops )
    return 1;
  if ( pTabStops && psrcTabStops && *pTabStops == *psrcTabStops )
  {
    v4 = 4 * *pTabStops;
    v5 = psrcTabStops + 1;
    v6 = (unsigned __int8 *)(pTabStops + 1);
    if ( v4 < 4 )
    {
LABEL_9:
      if ( !v4 )
        return 1;
    }
    else
    {
      while ( *(_DWORD *)v6 == *v5 )
      {
        v4 -= 4;
        ++v5;
        v6 += 4;
        if ( v4 < 4 )
          goto LABEL_9;
      }
    }
    return *v6 == *(unsigned __int8 *)v5
        && (v4 <= 1
         || v6[1] == *((unsigned __int8 *)v5 + 1) && (v4 <= 2 || v6[2] == *((unsigned __int8 *)v5 + 2) && v4 <= 3));
  }
  return 0;
}
