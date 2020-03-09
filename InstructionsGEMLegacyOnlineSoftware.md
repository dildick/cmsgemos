## Instructions by Jared Sturdy:

One will also need the xdaq, ipbus, and amc13 repo files. If they aren't easily available from the appropriate sources, I can put compatible versions somewhere.

So preliminary instructions are (as root, or prepend sudo):

```
curl -L https://cern.ch/cmsgemdaq/sw/gemos/repos/releases/legacy/gemos_release_centos7_x86_64.repo -o /etc/yum.repos.d/gemos.repo
```

Then, I think for *most* teststands this should be sufficient:

```
yum install xhal reedmuller wiscrpcsvc gempython\*
```

N.B., other things I tested as working (or almost working):

```
yum install gempython_vfatqc
```

(will pull in cmsgemos_gempython and numpy, vfatqc does not correctly depend on xhal so it's not pulling it in though it *should*)

```
yum install gempython_gemplotting --enablerepo=cernonly
```

(will pull in root, root_numpy, cx_Oracle (from cernonly), and several python deps)

```
yum install cmsgemos-gemsupervisor
```

(pulls in dependencies from cmsgemos as well as from xdaq)

```
yum install xhal
```

(pulls in nothing, but *should* pull in wiscrpcsvc)

Something should depend on reedmuller, not sure where the explicit dependency needs to be though...
