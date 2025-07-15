int __cdecl release_unused_segments(malloc_state *m)
{
  malloc_state *v1; // edi
  unsigned int sflags; // eax
  malloc_tree_chunk *v3; // ebx
  virtual_alloc_arena *p_size; // ecx
  virtual_alloc_region *bk; // esi
  malloc_tree_chunk *parent; // edx
  malloc_tree_chunk *fd; // eax
  virtual_alloc_arena *child; // eax
  malloc_tree_chunk **v9; // eax
  malloc_tree_chunk *v10; // eax
  malloc_tree_chunk *v11; // eax
  unsigned int v12; // eax
  unsigned int treemap; // ecx
  malloc_tree_chunk **v14; // edx
  unsigned int v15; // eax
  char *v16; // ecx
  char *least_addr; // esi
  malloc_tree_chunk *v18; // eax
  int v19; // eax
  char *ptr; // [esp+4h] [ebp-24h]
  malloc_segment *v22; // [esp+8h] [ebp-20h]
  malloc_segment *p_seg; // [esp+Ch] [ebp-1Ch]
  unsigned int size; // [esp+10h] [ebp-18h]
  int v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  malloc_segment *next; // [esp+20h] [ebp-8h]
  unsigned int v28; // [esp+24h] [ebp-4h]

  v25 = 0;
  v26 = 0;
  v1 = m;
  p_seg = &m->seg;
  next = m->seg.next;
  if ( !next )
  {
LABEL_61:
    v19 = 255;
    goto LABEL_62;
  }
  do
  {
    sflags = next->sflags;
    ++v26;
    ptr = next->base;
    size = next->size;
    v22 = next->next;
    if ( (sflags & 1) == 0 )
      goto LABEL_59;
    if ( (sflags & 8) != 0 )
      goto LABEL_59;
    v3 = (malloc_tree_chunk *)&next->base[((int)next->base & 7) != 0 ? -((int)next->base & 7) & 7 : 0];
    v28 = v3->head & 0xFFFFFFF8;
    if ( (v3->head & 2) != 0 )
      goto LABEL_59;
    p_size = (virtual_alloc_arena *)&next->base[next->size - 40];
    if ( (char *)v3 + (v3->head & 0xFFFFFFF8) < (char *)p_size )
      goto LABEL_59;
    if ( v3 == (malloc_tree_chunk *)v1->dv )
    {
      v1->dv = 0;
      v1->dvsize = 0;
    }
    else
    {
      bk = (virtual_alloc_region *)v3->bk;
      parent = v3->parent;
      if ( bk == (virtual_alloc_region *)v3 )
      {
        child = (virtual_alloc_arena *)&v3->child[1];
        bk = (virtual_alloc_region *)v3->child[1];
        if ( bk || (child = (virtual_alloc_arena *)v3->child, (bk = (virtual_alloc_region *)v3->child[0]) != 0) )
        {
          while ( 1 )
          {
            p_size = (virtual_alloc_arena *)&bk[1].size;
            if ( !bk[1].size )
            {
              p_size = (virtual_alloc_arena *)&bk[1].next_free_region;
              if ( !bk[1].next_free_region )
                break;
            }
            bk = p_size->first_free_region;
            child = p_size;
          }
          if ( (char *)child < v1->least_addr )
LABEL_18:
            abort();
          child->first_free_region = 0;
        }
      }
      else
      {
        fd = v3->fd;
        if ( (char *)fd < v1->least_addr )
          goto LABEL_18;
        fd->bk = (malloc_tree_chunk *)bk;
        bk->size = (unsigned int)fd;
      }
      if ( parent )
      {
        v9 = &v1->treebins[v3->index];
        if ( v3 == *v9 )
        {
          *v9 = (malloc_tree_chunk *)bk;
          if ( bk )
            goto LABEL_29;
          p_size = (virtual_alloc_arena *)v3->index;
          v1->treemap &= ~(1 << (char)p_size);
        }
        else
        {
          if ( (char *)parent < v1->least_addr )
            abort();
          if ( parent->child[0] == v3 )
            parent->child[0] = (malloc_tree_chunk *)bk;
          else
            parent->child[1] = (malloc_tree_chunk *)bk;
          if ( bk )
          {
LABEL_29:
            if ( (char *)bk < v1->least_addr )
              goto LABEL_37;
            bk[2].previous_free_region = (virtual_alloc_region *)parent;
            v10 = v3->child[0];
            if ( v10 )
            {
              if ( (char *)v10 < v1->least_addr )
                abort();
              bk[1].next_free_region = (virtual_alloc_region *)v10;
              v10->parent = (malloc_tree_chunk *)bk;
            }
            v11 = v3->child[1];
            if ( v11 )
            {
              if ( (char *)v11 < v1->least_addr )
LABEL_37:
                abort();
              bk[1].size = (unsigned int)v11;
              v11->parent = (malloc_tree_chunk *)bk;
            }
          }
        }
      }
    }
    if ( munmap(ptr, size, p_size) )
    {
      v12 = v28 >> 8;
      if ( v28 >> 8 )
      {
        if ( v12 <= 0xFFFF )
        {
          _BitScanReverse(&v12, v12);
          v12 = ((v28 >> (v12 + 7)) & 1) + 2 * v12;
        }
        else
        {
          v12 = 31;
        }
      }
      v3->child[1] = 0;
      v3->child[0] = 0;
      v3->index = v12;
      treemap = m->treemap;
      v14 = &m->treebins[v12];
      if ( ((1 << v12) & treemap) != 0 )
      {
        v14 = (malloc_tree_chunk **)*v14;
        v15 = v28 << (v12 != 31 ? 25 - (v12 >> 1) : 0);
        while ( 1 )
        {
          if ( ((unsigned int)v14[1] & 0xFFFFFFF8) == v28 )
          {
            least_addr = m->least_addr;
            v18 = v14[2];
            if ( v14 < (malloc_tree_chunk **)least_addr || v18 < (malloc_tree_chunk *)least_addr )
              abort();
            v18->bk = v3;
            v14[2] = v3;
            v3->parent = 0;
            v3->fd = v18;
            v3->bk = (malloc_tree_chunk *)v14;
            goto LABEL_58;
          }
          v16 = (char *)&v14[(v15 >> 31) + 4];
          v15 *= 2;
          if ( !*(_DWORD *)v16 )
            break;
          v14 = *(malloc_tree_chunk ***)v16;
        }
        if ( v16 < m->least_addr )
          abort();
        *(_DWORD *)v16 = v3;
      }
      else
      {
        m->treemap = treemap | (1 << v12);
        *v14 = v3;
      }
      v3->parent = (malloc_tree_chunk *)v14;
      v3->bk = v3;
      v3->fd = v3;
      v1 = m;
    }
    else
    {
      v25 += size;
      m->footprint -= size;
      next = p_seg;
      p_seg->next = v22;
LABEL_58:
      v1 = m;
    }
LABEL_59:
    p_seg = next;
    next = v22;
  }
  while ( v22 );
  v19 = v26;
  if ( v26 <= 255 )
    goto LABEL_61;
LABEL_62:
  v1->release_checks = v19;
  return v25;
}
