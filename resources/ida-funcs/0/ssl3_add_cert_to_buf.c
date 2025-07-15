int __usercall ssl3_add_cert_to_buf@<eax>(unsigned int *l@<esi>, x509_st *x@<edi>, buf_mem_st *buf)
{
  int v3; // ebx
  unsigned __int8 *out; // [esp+8h] [ebp-4h] BYREF

  v3 = i2d_X509(x, 0);
  if ( BUF_MEM_grow_clean(buf, *l + v3 + 3) )
  {
    out = (unsigned __int8 *)&buf->data[*l];
    *out = BYTE2(v3);
    out[1] = BYTE1(v3);
    out[2] = v3;
    out += 3;
    i2d_X509(x, &out);
    *l += v3 + 3;
    return 0;
  }
  else
  {
    ERR_put_error(v3, 0x14u, 296, 7, ".\\ssl\\s3_both.c", 307);
    return -1;
  }
}
