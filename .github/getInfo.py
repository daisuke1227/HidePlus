import json
import hashlib
import os
import sys
import zipfile
import urllib.request
import re
from pathlib import Path
import subprocess



archive = zipfile.ZipFile('coopeeo.hideplus.geode', 'r')
eee = archive.read('changelog.md')


if os.getenv('GITHUB_OUTPUT'):
	with open(os.getenv('GITHUB_OUTPUT'), 'a') as file:
		file.write('cl=' + ("# " + eee.split("##")[1]).replace((eee.split("##")[1]).split("\r")[0], "What's New This Update") + '\n'
if os.getenv('GITHUB_OUTPUT'):
	with open(os.getenv('GITHUB_OUTPUT'), 'a') as file:
		file.write('version=' + json.loads(archive.read('mod.json'))["version"] + '\n')