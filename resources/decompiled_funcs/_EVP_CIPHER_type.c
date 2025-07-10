int __cdecl EVP_CIPHER_type(const evp_cipher_st *ctx)
{
  int nid; // esi
  int result; // eax
  asn1_object_st *v3; // eax

  nid = ctx->nid;
  if ( ctx->nid > 421 )
  {
    switch ( nid )
    {
      case 425:
      case 651:
      case 654:
        result = 425;
        break;
      case 429:
      case 652:
      case 655:
        result = 429;
        break;
      case 650:
      case 653:
        return 421;
      case 656:
      case 657:
      case 658:
      case 659:
$LN5_24:
        result = 30;
        break;
      default:
LABEL_11:
        v3 = OBJ_nid2obj(ctx->nid);
        if ( !v3 || !v3->data )
          nid = 0;
        ASN1_OBJECT_free(v3);
        result = nid;
        break;
    }
  }
  else if ( ctx->nid == 421 )
  {
    return 421;
  }
  else
  {
    switch ( nid )
    {
      case 5:
      case 97:
        result = 5;
        break;
      case 30:
      case 61:
        goto $LN5_24;
      case 37:
      case 98:
      case 166:
        result = 37;
        break;
      default:
        goto LABEL_11;
    }
  }
  return result;
}
