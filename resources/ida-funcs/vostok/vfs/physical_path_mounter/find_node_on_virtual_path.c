vostok::vfs::base_node<1> *__userpurge vostok::vfs::physical_path_mounter::find_node_on_virtual_path@<eax>(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        int a2@<eax>,
        vostok::vfs::base_node<1> **out_overlapper)
{
  int v5; // eax
  int v6; // ecx
  vostok::vfs::base_node<1> *v7; // esi
  vostok::vfs::overlapped_node_iterator *v8; // ecx
  vostok::vfs::base_node<1> *v9; // edi
  vostok::vfs::overlapped_node_iterator *v10; // ecx
  int v12; // [esp+10h] [ebp-44h] BYREF
  vostok::vfs::base_node<1> *node; // [esp+14h] [ebp-40h]
  int v14; // [esp+18h] [ebp-3Ch]
  int v15; // [esp+1Ch] [ebp-38h]
  int v16; // [esp+20h] [ebp-34h]
  int v17; // [esp+24h] [ebp-30h]
  int v18; // [esp+28h] [ebp-2Ch]
  vostok::vfs::overlapped_node_iterator *v19; // [esp+2Ch] [ebp-28h]
  _DWORD v20[4]; // [esp+30h] [ebp-24h] BYREF
  int v21; // [esp+40h] [ebp-14h] BYREF
  vostok::vfs::base_node<1> *v22; // [esp+44h] [ebp-10h]
  int v23; // [esp+48h] [ebp-Ch]
  int v24; // [esp+4Ch] [ebp-8h]
  bool v25; // [esp+5Fh] [ebp+Bh]

  vostok::vfs::vfs_hashset::equal_range(
    (vostok::vfs::vfs_hashset *)this,
    (vostok::vfs::vfs_hashset *)(*(_DWORD *)(a2 + 1316) + 24),
    (char *)&v12,
    *(char **)(a2 + 72),
    lock_type_read);
  v5 = v12;
  v6 = v18;
  *out_overlapper = 0;
  v7 = node;
  v21 = v5;
  v23 = v14;
  v24 = v15;
  v20[0] = v16;
  v20[2] = v6;
  v8 = v19;
  v22 = node;
  v20[1] = v17;
  v20[3] = v19;
  v25 = v17 != 0;
  while ( 1 )
  {
    if ( (v7 != 0) == v25 )
    {
      v9 = 0;
      goto LABEL_7;
    }
    if ( vostok::vfs::mount_id_of_node<1>(v7) == *(_DWORD *)(a2 + 1320) )
      break;
    *out_overlapper = v7;
    vostok::vfs::overlapped_node_iterator::operator++(v8, (int)&v21);
    v7 = v22;
  }
  v9 = v7;
LABEL_7:
  vostok::vfs::overlapped_node_iterator::clear(v8, v20);
  vostok::vfs::overlapped_node_iterator::clear(v10, &v21);
  return v9;
}
