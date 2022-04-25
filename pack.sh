#!/bin/bash 

function pack()
{

cp u-boot.bin fip/bl33.bin

aml_encrypt=aml_encrypt_g12b

fip/blx_fix.sh fip/bl30.bin fip/zero_tmp fip/bl30_zero.bin fip/bl301.bin fip/bl301_zero.bin fip/bl30_new.bin bl30
			fip/blx_fix.sh fip/bl2.bin fip/zero_tmp fip/bl2_zero.bin fip/acs.bin fip/bl21_zero.bin fip/bl2_new.bin bl2
			fip/${aml_encrypt} --bl30sig --input fip/bl30_new.bin --output fip/bl30_new.bin.g12a.enc --level v3
			fip/${aml_encrypt} --bl3sig --input fip/bl30_new.bin.g12a.enc --output fip/bl30_new.bin.enc --level v3 --type bl30
			fip/${aml_encrypt} --bl3sig --input fip/bl31.img --output fip/bl31.img.enc --level v3 --type bl31
			fip/${aml_encrypt} --bl3sig --input fip/bl33.bin --compress lz4 --output fip/bl33.bin.enc --level v3 --type bl33 --compress lz4
			fip/${aml_encrypt} --bl2sig --input fip/bl2_new.bin --output fip/bl2.n.bin.sig
			fip/${aml_encrypt} --bootmk \
				--output fip/u-boot.bin \
				--bl2 fip/bl2.n.bin.sig \
				--bl30 fip/bl30_new.bin.enc \
				--bl31 fip/bl31.img.enc \
				--bl33 fip/bl33.bin.enc \
				--ddrfw1 fip/ddr4_1d.fw \
				--ddrfw2 fip/ddr4_2d.fw \
				--ddrfw3 fip/ddr3_1d.fw \
				--ddrfw4 fip/piei.fw \
				--ddrfw5 fip/lpddr4_1d.fw \
				--ddrfw6 fip/lpddr4_2d.fw \
				--ddrfw7 fip/diag_lpddr4.fw \
				--ddrfw8 fip/aml_ddr.fw \
				--ddrfw9 fip/lpddr3_1d.fw \
				--level v3

}

function flash()
{
	sudo dd if=fip/u-boot.bin.sd.bin of=/dev/sdb conv=fsync,notrunc bs=512 skip=1 seek=1
	sudo dd if=fip/u-boot.bin.sd.bin of=/dev/sdb conv=fsync,notrunc bs=1 count=444 
}

case "$1" in
	*)
		"$1";;
esac
