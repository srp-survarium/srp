Scaleform::Render::VertexElement **__userpurge Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find@<eax>(
        Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this@<ecx>,
        int a2@<eax>,
        Scaleform::Render::VertexElement *keys,
        Scaleform::Render::VertexElement *count)
{
  _DWORD *i; // esi
  Scaleform::Render::VertexElement **v5; // ebx
  Scaleform::Render::VertexElement *v6; // edi
  char *v7; // eax
  char *j; // [esp+Ch] [ebp-Ch]
  unsigned int v10; // [esp+10h] [ebp-8h]
  Scaleform::Render::VertexElement *v11; // [esp+14h] [ebp-4h]

  for ( i = *(_DWORD **)(a2 + 8); ; i = (_DWORD *)*i )
  {
    if ( !i )
      return 0;
    v10 = 0;
    if ( i[1] )
      break;
LABEL_12:
    ;
  }
  v5 = (Scaleform::Render::VertexElement **)(i + 2);
  while ( 1 )
  {
    if ( v5[1] == count )
    {
      v11 = 0;
      if ( count )
      {
        v6 = *v5;
        v7 = (char *)((char *)keys - (char *)*v5);
        for ( j = v7;
              Scaleform::Render::VertexElement::operator==(
                v6,
                (const Scaleform::Render::VertexElement *)&v7[(_DWORD)v6]);
              v7 = j )
        {
          v11 = (Scaleform::Render::VertexElement *)((char *)v11 + 1);
          ++v6;
          if ( v11 >= count )
            break;
        }
      }
      if ( v11 == count )
        return v5 + 2;
    }
    ++v10;
    v5 += 5;
    if ( v10 >= i[1] )
      goto LABEL_12;
  }
}
